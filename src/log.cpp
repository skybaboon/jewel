#include "log.hpp"

// We deliberately do NOT use "jewel/assert.hpp" here,
// as we might one day want a call the assert to invoke
// logging facilities, and we don't want to create
// circularity here.
#include <cassert>

#include <ctime>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>

using std::begin;
using std::cerr;
using std::clog;
using std::cout;
using std::end;
using std::endl;
using std::ios;
using std::localtime;
using std::ofstream;
using std::ostream;
using std::strftime;
using std::string;
using std::time;
using std::time_t;
using std::tm;

namespace jewel
{

namespace
{
	// If current date and time can be obtained and formatted
	// successfully, writes a single field to p_os (a record
	// should already have been commenced) with this date and time.
	// Otherwise, does nothing. Does not write a newline at the end.
	// But does commence with a newline.
	void write_date_time_now(ostream& p_os)
	{
		time_t const now = time(0);
		if (now != static_cast<time_t>(-1))
		{
			// WARNING std::localtime may not be thread-safe.
			tm const* const now_local = localtime(&now);
			if (!now_local)
			{
				return;
			}
			assert (now_local != 0);
			size_t const date_time_str_len =
				10 +     // for ISO date format
				1 +      // for ISO 'T' character separating date & time
				8;       // for ISO local time format
			char date_time_arr[date_time_str_len + 1];
			char const* format_str = "%Y-%m-%dT%H:%M:%S";
			size_t const check = strftime
			(	date_time_arr,
				date_time_str_len + 1,
				format_str,
				now_local
			);
			if (check == date_time_str_len)
			{
				p_os << "\n{FIELD}[date_time_written]"
				     << date_time_arr;
			}
		}
		return;	
	}
	
	long long next_id()
	{
		static long long ret = -1;
		return ++ret;
	}

	struct StreamHolder
	{
		explicit StreamHolder(ostream* p_os);
		StreamHolder(StreamHolder const&) = delete;
		StreamHolder(StreamHolder&&) = delete;
		StreamHolder& operator=(StreamHolder const&) = delete;
		StreamHolder& operator=(StreamHolder&&) = delete;
		~StreamHolder();
		
		void kill();
		ostream* os;
	};

	StreamHolder::StreamHolder(ostream* p_os): os(p_os)
	{
	}

	StreamHolder::~StreamHolder()
	{
		JEWEL_LOG_MESSAGE(Log::info, "Destroying logging StreamHolder.");
		kill();
	}

	void StreamHolder::kill()
	{
		if (os)
		{
			*os << "{RECORD}\n{FIELD}[id]" << next_id()
			    << "\n{FIELD}[message]End log";
			write_date_time_now(*os);
			*os << endl;
			if ((os != &cerr) && (os != &clog) && (os != &cout))
			{
				delete os;
			}
			os = 0;
		}
		assert (0 == os);
		return;
	}

}  // end anonymous namespace

void
Log::set_filepath(string const& p_filepath)
{
	static string filepath = "";
	if (p_filepath != filepath)
	{
		filepath = p_filepath;
		if (!filepath.empty())
		{
			ofstream* f = new ofstream(filepath.c_str());
			f->exceptions(ios::iostate(0));
			stream_aux(f);
			ostream* const osp = stream_aux();
			if (osp)
			{
				*osp << "{RECORD}\n{FIELD}[id]" << next_id()
		   			 << "\n{FIELD}[message]"
					 << "Commenced logging to "
					 << filepath
					 << ".";
				write_date_time_now(*osp);
				*osp << '\n' << endl;
			}
		}
	}
	return;
}

void
Log::set_threshold(Level p_level)
{
	threshold_aux() = p_level;
	return;
}

void
Log::log
(	Level p_severity,
	string const& p_message,
	string const& p_function,
	string const& p_file,
	int p_line,
	string const& p_compilation_date,
	string const& p_compilation_time,
	string const& p_exception_type
)
{
	log
	(	p_severity,
		p_message.c_str(),
		p_function.c_str(),
		p_file.c_str(),
		p_line,
		p_compilation_date.c_str(),
		p_compilation_time.c_str(),
		p_exception_type.c_str()
	);
	return;
}

void
Log::log
(	Level p_severity,
	char const* p_message,
	char const* p_function,
	char const* p_file,
	int p_line,
	char const* p_compilation_date,
	char const* p_compilation_time,
	char const* p_exception_type,
	char const* p_expression,
	char const* p_value
)
{
	if (p_severity >= threshold_aux())
	{
		ostream* const osp = stream_aux();
		if (!osp)
		{
			return;
		}
		assert (!osp->bad());  // guaranteed by stream_aux().
		assert (!osp->exceptions());  // guaranteed by stream_aux().
		*osp << "{RECORD}\n"
			<< "{FIELD}[id]" << next_id() << '\n'
			<< "{FIELD}[severity]" << severity_string(p_severity) << '\n';
		if (p_message)
		{
			*osp << "{FIELD}[message]" << p_message << '\n';
		}
		*osp << "{FIELD}[function]" << p_function << '\n'
			 << "{FIELD}[file]" << p_file << '\n'
			 << "{FIELD}[line]" << p_line << '\n';
		if (p_compilation_date)
		{
			*osp << "{FIELD}[compilation_date]" << p_compilation_date << '\n';
		}
		if (p_compilation_time)
		{
			*osp << "{FIELD}[compilation_time]" << p_compilation_time << '\n';
		}
		if (p_exception_type)
		{
			*osp << "{FIELD}[exception_type]" << p_exception_type << '\n';
		}
		if (p_expression)
		{
			*osp << "{FIELD}[expression]" << p_expression << '\n';
		}
		if (p_value)
		{
			*osp << "{FIELD}[value]" << p_value << '\n';
		}
		*osp << endl;
	}
	return;
}


char const*
Log::severity_string(Level p_level)
{
	static char const* strings[] =
	{	"trace",
		"info",
		"warning",
		"error"
	};
	if (p_level >= (end(strings) - begin(strings)))
	{
		return "unrecognized";
	}
	return strings[p_level];
}

std::ostream*
Log::stream_aux(std::ostream* p_stream)
{
	static StreamHolder holder(0);

	if (p_stream != 0)
	{
		// Then set the stream.
		holder.kill();	
		holder.os = p_stream;
	}

	// Make sure the stream isn't in a bad state.
	if (holder.os && holder.os->bad())
	{
		holder.kill();
		assert (0 == holder.os);
	}

	assert
	(	(0 == holder.os) ||
		(!holder.os->bad() && !holder.os->exceptions())
	);

	return holder.os;
}


}  // namespace jewel
STXXL_CXX			 = g++
STXXL_CPPFLAGS			 =  $(STXXL_CPPFLAGS_STXXL)
STXXL_LDLIBS			 =  $(STXXL_LDLIBS_STXXL)
STXXL_CPPFLAGS_STXXL		 =   -I/Users/mandalin/Desktop/DissertationCODE/stxxl/stxxl-1.3.1/include -include stxxl/bits/defines.h -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE 
STXXL_LDLIBS_STXXL		 =  -L/Users/mandalin/Desktop/DissertationCODE/stxxl/stxxl-1.3.1/lib -lstxxl
STXXL_LIBDEPS			 = /Users/mandalin/Desktop/DissertationCODE/stxxl/stxxl-1.3.1/lib/libstxxl.a
STXXL_CPPFLAGS_PARALLEL_MODE	 = 
STXXL_LDLIBS_PARALLEL_MODE	 = 
STXXL_CPPFLAGS_MCSTL		 = 
STXXL_LDLIBS_MCSTL		 = 
STXXL_CPPFLAGS_BOOST		 =  -DSTXXL_BOOST_CONFIG -DSTXXL_BOOST_FILESYSTEM -DSTXXL_BOOST_RANDOM -DSTXXL_BOOST_THREADS
STXXL_LDLIBS_BOOST		 =  -lboost_thread-mt -lboost_date_time-mt -lboost_iostreams-mt -lboost_system-mt -lboost_filesystem-mt
STXXL_WARNFLAGS			 = -W -Wall -Woverloaded-virtual -Wundef 
STXXL_DEBUGFLAGS		 = 

# master SConstruct for tibeecompare
#
# author: Francois Doray <francois.pierre-doray@polymtl.ca>


import os


# build mode (debug/release; default to release)
build_mode = ARGUMENTS.get('mode', 'release')

if build_mode not in ['debug', 'release']:
    sys.stderr.write('Oh noes: only "debug" and "release" build modes are supported\n')
    Exit(1)

# C++ flags and defines
ccflags = [
    '-pthread',
    '-std=c++11',
    '-Wall',
    '-pedantic-errors',
]

cppdefines = []

if build_mode == 'debug':
    ccflags += ['-g', '-O0']
    cppdefines += ['_DEBUG']
elif build_mode == 'release':
    ccflags += ['-O2']
    cppdefines += ['NDEBUG']

# this is to allow colorgcc
custom_env = {
    'PATH': os.environ['PATH'],
    'TERM': os.environ['TERM'],
    'HOME': os.environ['HOME'],
}

root_env = Environment(CXXFLAGS=ccflags,
                       CPPDEFINES=cppdefines,
                       ENV=custom_env)

if 'CXX' in os.environ:
    root_env['CXX'] = os.environ['CXX']

if 'TIGERBEETLE_CPPPATH' in os.environ:
    root_env.Append(CPPPATH=[os.environ['TIGERBEETLE_CPPPATH']])

if 'TIGERBEETLE_LIBPATH' in os.environ:
    root_env.Append(LIBPATH=[os.environ['TIGERBEETLE_LIBPATH']])

if 'LIBDELOREAN_CPPPATH' in os.environ:
    root_env.Append(CPPPATH=[os.environ['LIBDELOREAN_CPPPATH']])

if 'LIBDELOREAN_LIBPATH' in os.environ:
    root_env.Append(LIBPATH=[os.environ['LIBDELOREAN_LIBPATH']])

if 'BABELTRACE_CPPPATH' in os.environ:
    root_env.Append(CPPPATH=[os.environ['BABELTRACE_CPPPATH']])

if 'BABELTRACE_LIBPATH' in os.environ:
    root_env.Append(LIBPATH=[os.environ['BABELTRACE_LIBPATH']])

if 'BABELTRACE_CTF_LIBPATH' in os.environ:
    root_env.Append(LIBPATH=[os.environ['BABELTRACE_CTF_LIBPATH']])

if 'LEVELDB_INCLUDEPATH' in os.environ:
    root_env.Append(CPPPATH=[os.environ['LEVELDB_INCLUDEPATH']])

if 'LEVELDB_LIBPATH' in os.environ:
    root_env.Append(LIBPATH=[os.environ['LEVELDB_LIBPATH']])

if 'LD_LIBRARY_PATH' in os.environ:
    root_env['ENV']['LD_LIBRARY_PATH'] = os.environ['LD_LIBRARY_PATH']

Export('root_env')

apps = SConscript(os.path.join('src', 'SConscript'))

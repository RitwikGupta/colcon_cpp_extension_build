#from distutils.core import setup, Extension
from setuptools import setup, Extension
from distutils.sysconfig import get_python_inc
import numpy 

sources=[
        'PythonBindings.cpp',
]

xlib_module = Extension(
    'xlib',
    sources=sources,
    language='C++',
    extra_compile_args=['-std=c++14'],
    libraries=['stdc++'],
    include_dirs=[numpy.get_include(), get_python_inc()]
)

setup(
    name='xlib_bindings',
    version='1.0.0',
    packages=[],
    author='Ritwik Gupta',
    author_email='nonexistent@sei.cmu.edu',
    maintainer='Ritwik Gupta',
    maintainer_email='nonexistent@sei.cmu.edu',
    keywords=['XLib'],
    classifiers=[],
    description='XLib bindings to go from C++ to Python',
    ext_modules=[xlib_module],
    package_data={
        '': ['PythonBindings.cpp', '*.h', '*.c']
    },
    include_package_data=True
)

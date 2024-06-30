# from distutils.core import setup, Extension
from setuptools import setup, Extension

PiQen = Extension('PiQen', include_dirs = ['./qentem/Include'],
                    sources = ['piqen.cpp'], language='c++')

setup (name = 'PiQen',
       version = '2.2.9',
       description = 'Fast template rendering module',
       url = 'https://github.com/HaniAmmar/PiQen',
       ext_modules = [PiQen])

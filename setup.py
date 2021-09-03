# from distutils.core import setup, Extension
from setuptools import setup, Extension

module1 = Extension('PiQen',include_dirs = ['./qentem/Include'],
                    sources = ['piqen.cpp'], language='c++')

setup (name = 'PiQen',
       version = '1.7',
       description = 'Fast template rendering module',
       url = 'https://github.com/HaniAmmar/PiQen',
       ext_modules = [module1])

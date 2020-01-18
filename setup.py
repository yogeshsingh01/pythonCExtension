#!/usr/bin/env python
# -*- coding: utf-8 -*-

from setuptools import Extension, setup

__version__ = '0.0.1'

ymath_src = ['src/ymath.c']
ymath_dep = ['']

ymath_ext = Extension('ymath', ymath_src, depends=ymath_dep,
                       extra_compile_args=['-std=c99'])

setup(name='ymath', version = __version__,
      ext_modules = [ymath_ext],
      description = 'A python wrapper module for thelearning python extension.',
      url = '',
      author = 'Yogesh Singh',
      author_email = 'yogesh_official@outlook.com',
      maintainer = 'Yogesh Singh',
      maintainer_email = 'yogesh_official@outlook.com',
      license = 'GNU GPLv2',
      long_description=open('README.md').read(),
)

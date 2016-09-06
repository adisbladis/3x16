from distutils.core import setup, Extension

x16_hash_module = Extension('x16_hash',
                               sources = ['x16module.c',
                                          'x16o.c',
                                          'x16r.c',
                                          'x16c.c',
										  'sha3/blake.c',
										  'sha3/bmw.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c',
										  'sha3/cubehash.c',
										  'sha3/echo.c',
										  'sha3/luffa.c',
										  'sha3/simd.c',
										  'sha3/hamsi.c',
										  'sha3/hamsi_helper.c',
										  'sha3/fugue.c',
										  'sha3/shavite.c',
										  'sha3/shabal.c',
										  'sha3/whirlpool.c',
										  'sha3/sha2big.c'],

                               include_dirs=['.', './sha3'])

setup (name = 'x16_hash',
       version = '1.0',
       description = 'Bindings for proof of work used by X16',
       ext_modules = [x16_hash_module])

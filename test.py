from binascii import unhexlify
import x16_hash


teststart = ''.join((
    '14d079970b29a9418fd0549e7d68a95c7f168621a314201049fd07b22f3a8a34',
    '7c516de7052f034d2b76ff68e0d6ecff9b77a45489e3fd511732011df0731000'))
testbin = unhexlify(teststart)
print(x16_hash.getPoWHash_o(testbin))
print(x16_hash.getPoWHash_r(testbin))
print(x16_hash.getPoWHash_c(testbin))

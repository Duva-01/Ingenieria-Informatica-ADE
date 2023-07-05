#
# Autogenerated by Thrift Compiler (0.13.0)
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#
#  options string: py
#

from thrift.Thrift import TType, TMessageType, TFrozenDict, TException, TApplicationException
from thrift.protocol.TProtocol import TProtocolException
from thrift.TRecursive import fix_spec

import sys

from thrift.transport import TTransport
all_structs = []


class Operacion(object):
    """
    Attributes:
     - a
     - operador
     - b

    """


    def __init__(self, a=None, operador=None, b=None,):
        self.a = a
        self.operador = operador
        self.b = b

    def read(self, iprot):
        if iprot._fast_decode is not None and isinstance(iprot.trans, TTransport.CReadableTransport) and self.thrift_spec is not None:
            iprot._fast_decode(self, iprot, [self.__class__, self.thrift_spec])
            return
        iprot.readStructBegin()
        while True:
            (fname, ftype, fid) = iprot.readFieldBegin()
            if ftype == TType.STOP:
                break
            if fid == 1:
                if ftype == TType.DOUBLE:
                    self.a = iprot.readDouble()
                else:
                    iprot.skip(ftype)
            elif fid == 2:
                if ftype == TType.STRING:
                    self.operador = iprot.readString().decode('utf-8') if sys.version_info[0] == 2 else iprot.readString()
                else:
                    iprot.skip(ftype)
            elif fid == 3:
                if ftype == TType.DOUBLE:
                    self.b = iprot.readDouble()
                else:
                    iprot.skip(ftype)
            else:
                iprot.skip(ftype)
            iprot.readFieldEnd()
        iprot.readStructEnd()

    def write(self, oprot):
        if oprot._fast_encode is not None and self.thrift_spec is not None:
            oprot.trans.write(oprot._fast_encode(self, [self.__class__, self.thrift_spec]))
            return
        oprot.writeStructBegin('Operacion')
        if self.a is not None:
            oprot.writeFieldBegin('a', TType.DOUBLE, 1)
            oprot.writeDouble(self.a)
            oprot.writeFieldEnd()
        if self.operador is not None:
            oprot.writeFieldBegin('operador', TType.STRING, 2)
            oprot.writeString(self.operador.encode('utf-8') if sys.version_info[0] == 2 else self.operador)
            oprot.writeFieldEnd()
        if self.b is not None:
            oprot.writeFieldBegin('b', TType.DOUBLE, 3)
            oprot.writeDouble(self.b)
            oprot.writeFieldEnd()
        oprot.writeFieldStop()
        oprot.writeStructEnd()

    def validate(self):
        if self.a is None:
            raise TProtocolException(message='Required field a is unset!')
        if self.operador is None:
            raise TProtocolException(message='Required field operador is unset!')
        if self.b is None:
            raise TProtocolException(message='Required field b is unset!')
        return

    def __repr__(self):
        L = ['%s=%r' % (key, value)
             for key, value in self.__dict__.items()]
        return '%s(%s)' % (self.__class__.__name__, ', '.join(L))

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.__dict__ == other.__dict__

    def __ne__(self, other):
        return not (self == other)
all_structs.append(Operacion)
Operacion.thrift_spec = (
    None,  # 0
    (1, TType.DOUBLE, 'a', None, None, ),  # 1
    (2, TType.STRING, 'operador', 'UTF8', None, ),  # 2
    (3, TType.DOUBLE, 'b', None, None, ),  # 3
)
fix_spec(all_structs)
del all_structs

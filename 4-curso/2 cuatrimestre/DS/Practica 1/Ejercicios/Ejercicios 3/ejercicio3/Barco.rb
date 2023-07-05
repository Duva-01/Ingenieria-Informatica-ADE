require_relative 'Builder'

class Barco
  @mastil
  @proa
  @timon


  def aniadirMastil(m)
    @mastil = m
  end

  def aniadirProa(p)
    @proa = p
  end

  def aniadirTimon(t)
    @timon  = t
  end

  def toString()
    tmp=  "Presentacion de las partes: " + @mastil.toString() + "," + @proa.toString() + "," +  @timon.toString()
    tmp
  end

end

class DirectorBarco
  @builder

  def construirBarco()
    @builder.crearProa()
    @builder.crearTimon()
    @builder.crearMastil()
  end



  def initialize(builder)
    @builder=builder
  end

end

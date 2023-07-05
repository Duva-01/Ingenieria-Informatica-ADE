require_relative 'Visitante'
class Mastil

  attr_reader :distancia, :metroscuadrados
  @distancia
  @metroscuadrados


  def initialize (distancia, metroscuadrados)
    @distancia = distancia
    @metroscuadrados = metroscuadrados
  end

  def accept(vistante)

  end


end

class MastilPequenio < Mastil

  def accept(vistante)
    vistante.visitarMastil(self)
  end
end

class MastilGrande < Mastil

  def accept(vistante)
    vistante.visitarMastil(self)
  end
end


class Proa

  attr_reader :distancia, :metroscuadrados
  @distancia
  @metroscuadrados


  def initialize (distancia, metroscuadrados)
    @distancia = distancia
    @metroscuadrados = metroscuadrados
  end

  def accept(vistante)

  end


end

class ProaPequenia < Proa

  def accept(vistante)
    vistante.visitarProa(self)
  end
end

class ProaGrande < Proa

  def accept(vistante)
    vistante.visitarProa(self)
  end
end


class Timon

  attr_reader :distancia, :metroscuadrados
  @distancia
  @metroscuadrados


  def initialize (distancia, metroscuadrados)
    @distancia = distancia
    @metroscuadrados = metroscuadrados
  end

  def accept(vistante)

  end


end

class TimonPequenio < Timon

  def accept(vistante)
    vistante.visitarTimon(self)
  end
end

class TimonGrande < Timon

  def accept(vistante)
    vistante.visitarTimon(self)
  end

end
class Barco
  attr_reader :mastil, :proa, :timon

  @mastil
  @proa
  @timon

  def initialize (mastil,proa,timon)
    @mastil = mastil
    @proa = proa
    @timon = timon
  end


end




#puts MastilPequenio.new.toString
#puts MastilGrande.new.toString
#puts TimonPequenio.new.toString
# puts ProaGrande.new.toString


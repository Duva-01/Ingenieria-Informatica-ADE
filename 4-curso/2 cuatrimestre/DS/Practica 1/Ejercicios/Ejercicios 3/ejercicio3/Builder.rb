require_relative 'Partes'
require_relative 'Barco'

class BuilderBarco
  @resultado

  def initialize
    @resultado=Barco.new
  end #hasta q no se ponga la clase barco da error

  def getResultado
    @resultado
  end

  def crearProa()
  end

  def crearMastil()
  end

  def crearTimon()
  end

end

class BuilderGrande < BuilderBarco
  def crearProa()
    proa = ProaGrande.new
    @resultado.aniadirProa(proa)
    #@resultado = "soy grande"  para probar
  end

  def crearMastil()
    mastil = MastilGrande.new
    @resultado.aniadirMastil(mastil)
  end

  def crearTimon()
    timon = TimonGrande.new
    @resultado.aniadirTimon(timon)
  end
end


class BuilderPequenio < BuilderBarco
  def crearProa()
    proa = ProaPequenia.new
    @resultado.aniadirProa(proa)
  end

  def crearMastil()
    mastil = MastilPequenio.new
    @resultado.aniadirMastil(mastil)

  end

  def crearTimon()
    timon = TimonPequenio.new
    @resultado.aniadirTimon(timon)
  end
end




require_relative 'Barco'

class VisitanteBarcos

  def visitarMastil(mastil)

  end

  def visitarProa(proa)

  end

  def visitarTimon(timon)

  end

end

class VisitanteAreaTotalBarcos < VisitanteBarcos

  def visitarMastil(mastil)
    mastil.metroscuadrados
  end

  def visitarProa(proa)
    proa.metroscuadrados
  end

  def visitarTimon(timon)
    timon.metroscuadrados
  end

end

class VisitantesDistanciaBarcos < VisitanteBarcos

  def visitarMastil(mastil)
    mastil.distancia
  end

  def visitarProa(proa)
    proa.distancia
  end

  def visitarTimon(timon)
    timon.distancia
  end
end

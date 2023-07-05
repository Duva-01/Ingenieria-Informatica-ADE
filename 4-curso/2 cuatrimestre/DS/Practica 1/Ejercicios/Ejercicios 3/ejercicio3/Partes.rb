class Mastil
  def toString
    "Soy un mástil"
  end
end

class MastilPequenio < Mastil
  def toString()
    tmp=super
    tmp+=" pequeño"
    tmp
  end
end

class MastilGrande < Mastil
  def toString()
    tmp=super
    tmp+= " grande"
    tmp
  end
end

class Proa
  def toString
    "Soy una proa"
  end
end

class ProaPequenia < Proa
  def toString()
    tmp=super
    tmp+=" pequeño"
    tmp
  end
end

class ProaGrande < Proa
  def toString()
    tmp=super
    tmp+= " grande"
    tmp
  end
end


class Timon
  def toString
    "Soy un timon"
  end
end

class TimonPequenio < Timon
  def toString()
    tmp=super
    tmp+=" pequeño"
    tmp
  end
end

class TimonGrande < Timon
  def toString()
    tmp=super
    tmp+= " grande"
    tmp
  end
end




#puts MastilPequenio.new.toString
#puts MastilGrande.new.toString
#puts TimonPequenio.new.toString
# puts ProaGrande.new.toString
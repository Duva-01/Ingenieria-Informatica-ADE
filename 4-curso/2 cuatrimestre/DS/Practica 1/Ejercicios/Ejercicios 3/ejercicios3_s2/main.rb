require_relative 'Barco'


mastil = MastilPequenio.new(4,2)
proa = ProaGrande.new(20,200)
timon = TimonPequenio.new(2,2)

barco = Barco.new(mastil,proa,timon)



visitante = VisitanteAreaTotalBarcos.new

puts ("Area Total : " +  barco.mastil.accept(visitante).to_s + " metros de mastil " + barco.proa.accept(visitante).to_s + " metros de proa " +
  barco.timon.accept(visitante).to_s + " metros de timon")




visitante = VisitantesDistanciaBarcos.new

puts ("Distancia Total : " +  barco.mastil.accept(visitante).to_s + " metros de mastil " + barco.proa.accept(visitante).to_s + " metros de proa " +
  barco.timon.accept(visitante).to_s + " metros de timon")










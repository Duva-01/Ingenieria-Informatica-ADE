require_relative 'Builder'


builderBarco = BuilderGrande.new
director = DirectorBarco.new(builderBarco)
director.construirBarco
barco= builderBarco.getResultado


puts "Voy a crear un barco grande"
puts barco.toString()

builderBarco = BuilderPequenio.new
director = DirectorBarco.new(builderBarco)
director.construirBarco
barco= builderBarco.getResultado

puts "Voy a crear un barco pequeño"
puts barco.toString()


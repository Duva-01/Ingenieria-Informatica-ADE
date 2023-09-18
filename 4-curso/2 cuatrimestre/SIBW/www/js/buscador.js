$(document).ready(function() {

    $("#buscadorAdmin").on("input", function() {
        
        var busquedaAdmin = $("#buscadorAdmin").val();
        
        $.ajax({
            url: "/buscarCientifico.php",
            method: "POST",
            data: { busquedaAdmin: busquedaAdmin },
            dataType: "json",
            success: function(response) {
                var cientificos = response.cientificos;
                var html = "";
                for (var i = 0; i < cientificos.length; i++) {
                    var cientifico = cientificos[i];
                    html += "<tr>" +
                        "<td><a href='/cientifico/" + cientifico.id + "'>" + cientifico.nombre + "</a></td>" +
                        "<td>" + cientifico.nacimiento + "</td>" +
                        "<td>" + cientifico.muerte + "</td>" +
                        "<td>" + cientifico.ciudad + "</td>" +
                        "<td>" + cientifico.publicado + "</td>" +
                        "</tr>";
                }
                $("#tablaResultados tbody").html(html);
            },
            error: function(xhr, status, error) {
                // Agrega un mensaje de depuración
                console.log('Error en la solicitud AJAX: ' + error);
            }
        });
    });
});


$(document).ready(function() {

    $("#buscador").on("input", function() {
        
        var busqueda = $("#buscador").val();
        
        $.ajax({
            url: "/buscarCientifico.php",
            method: "POST",
            data: { busqueda: busqueda },
            dataType: "json",
            success: function(response) {
                var cientificos = response.cientificos;
                var html = "";
                for (var i = 0; i < cientificos.length; i++) {
                    var cientifico = cientificos[i];
                    html += "<tr>" +
                        "<td><a href='/cientifico/" + cientifico.id + "'>" + cientifico.nombre + "</a></td>" +
                        "<td>" + cientifico.nacimiento + "</td>" +
                        "<td>" + cientifico.muerte + "</td>" +
                        "<td>" + cientifico.ciudad + "</td>" +
                        "<td>" + cientifico.publicado + "</td>" +
                        "</tr>";
                }
                $("#tablaResultados tbody").html(html);
            },
            error: function(xhr, status, error) {
                // Agrega un mensaje de depuración
                console.log('Error en la solicitud AJAX: ' + error);
            }
        });
    });
});

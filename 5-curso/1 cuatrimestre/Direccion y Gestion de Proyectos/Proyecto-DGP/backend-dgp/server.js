const express = require('express');
const mysql = require('mysql');
const cors = require('cors');
const bodyParser = require('body-parser');

const app = express();
const PORT = 3000;

app.use(bodyParser.json()); // para peticiones con cuerpo tipo application/json
app.use(bodyParser.urlencoded({ extended: true })); // para peticiones con cuerpo tipo application/x-www-form-urlencoded

app.use(cors());

// Modificar la conexión para que utilice 'APPDGP' como nombre de la base de datos
const db = mysql.createConnection({
    host: process.env.DATABASE_HOST,
    user: process.env.DATABASE_USER,
    password: process.env.DATABASE_PASSWORD,
    database: 'APPDGP'  // Aquí especificamos el nombre de tu base de datos directamente
});

db.connect((err) => {
    if(err) throw err;
    console.log('Connected to the database');
});

app.get('/', (req, res) => {
    res.send('Hola desde Node.js con MySQL!');
});

// Nueva ruta para obtener administradores
app.get('/administradores', (req, res) => {
    db.query('SELECT * FROM administrador', (err, rows) => {
        if (err) {
            res.status(500).send("Error al obtener datos");
            return;
        }
        res.json(rows);
    });
});

// en tu server.js o donde tengas tus rutas

app.post('/login', (req, res) => {
    const { username, password } = req.body;

    db.query('SELECT * FROM administrador WHERE username = ?', [username], (err, results) => {
        if (err) {
            res.status(500).send("Error en la consulta");
            return;
        }

        if (results.length > 0 && results[0].password === password) {
            res.json({ status: 'success', message: 'Inicio de sesión exitoso' });
        } else {
            res.json({ status: 'error', message: 'Usuario o contraseña incorrectos' });
        }
    });
});


// Implementamos a los alumnos en la base de datos

app.get('/alumnos', (req, res) => {
    db.query('SELECT * FROM alumnos', (err, rows) => {
        if (err) {
            res.status(500).send("Error al obtener datos");
            return;
        }
        res.json(rows);
    });
});

// Ruta para agregar un nuevo alumno
app.post('/alumnos', (req, res) => {
    const { DNI, nombre, domicilio, fecha_nacimiento } = req.body;
    const query = 'INSERT INTO alumnos (DNI, nombre, domicilio, fecha_nacimiento) VALUES (?, ?, ?, ?)';
    db.query(query, [DNI, nombre, domicilio, fecha_nacimiento], (err, results) => {
        if (err) {
            res.status(500).send("Error al insertar");
            return;
        }
        res.json({ status: 'success', message: 'Alumno añadido exitosamente' });
    });
});

//----------------------- CREACION DE TAREAS Y ELEMENTO TAREAS -------------------------------//

app.get('/tareas', (req, res) => {
    db.query('SELECT * FROM tareas', (error, results) => {
        if (error) {
            return res.status(500).json({ error });
        }
        res.json(results);
    });
});

app.post('/tareas', (req, res) => {
    const { nombre, tipo } = req.body;

    db.query('INSERT INTO tareas (nombre, tipo) VALUES (?, ?)', [nombre, tipo], (error, results) => {
        if (error) {
            return res.status(500).json({ error });
        }
        res.json({ success: true, id: results.insertId });
    });
});

app.post('/tareas/:id/elementos', (req, res) => {
    const tareaId = req.params.id;
    const { pictograma, descripcion, sonido, video } = req.body;
    db.query('INSERT INTO elementoTarea (pictograma, descripcion, sonido, video, tarea_id) VALUES (?, ?, ?, ?, ?)', [pictograma, descripcion, sonido, video, tareaId], (error, results) => {
        if (error) {
            return res.status(500).json({ error });
        }
        res.json({ success: true, id: results.insertId });
    });
});

app.get('/tareas/:id/elementos', (req, res) => {
    const tareaId = req.params.id;

    db.query('SELECT * FROM elementoTarea WHERE tarea_id = ?', [tareaId], (error, results) => {
        if (error) {
            return res.status(500).json({ error });
        }
        res.json({ success: true, elementos: results });
    });
});


app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});

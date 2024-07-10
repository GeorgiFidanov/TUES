const express = require('express');
const http = require('http');
const socketIO = require('socket.io');

const app = express();
const server = http.createServer(app);
const io = socketIO(server);

app.use(express.static('static'));

let players = {};
let currentPlayer = 'X';

io.on('connection', (socket) => {
  console.log('A user connected');

  // Assign X or O to the player
  players[socket.id] = currentPlayer;
  currentPlayer = currentPlayer === 'X' ? 'O' : 'X';

  // Send the assigned player symbol to the client
  socket.emit('assignSymbol', players[socket.id]);

  // Listen for moves from clients
  socket.on('move', (index) => {
    io.emit('move', { index, symbol: players[socket.id] });
  });

  // Listen for disconnects
  socket.on('disconnect', () => {
    delete players[socket.id];
    console.log('A user disconnected');
  });
});

const port = process.env.PORT || 3000;
server.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});

const cells = document.querySelectorAll('.cell');
const statusText = document.querySelector('#statusText');
const restartBtn = document.querySelector('#restartBtn');
let options = ['', '', '', '', '', '', '', '', ''];
let currentPlayer = '';
let running = false;
let socket;

initializeGame();

function initializeGame() {
  socket = io();

  socket.on('assignSymbol', (symbol) => {
    currentPlayer = symbol;
    statusText.textContent = `${currentPlayer}'s turn`;
  });

  socket.on('move', ({ index, symbol }) => {
    const cell = cells[index];
    updateCell(cell, index);
    currentPlayer = symbol;
    statusText.textContent = `${currentPlayer}'s turn`;
    checkWinner();
  });

  socket.on('restart', () => {
    restartGame();
  });

  cells.forEach((cell) => cell.addEventListener('click', cellClicked));
  restartBtn.addEventListener('click', restartGame);
  statusText.textContent = 'Waiting for players...';
}

function cellClicked() {
  const cellIndex = this.getAttribute('cellIndex');

  if (options[cellIndex] !== '' || !running || currentPlayer === '') {
    return;
  }

  updateCell(this, cellIndex);
  socket.emit('move', cellIndex);
  checkWinner();
}

function updateCell(cell, index) {
  options[index] = currentPlayer;
  cell.textContent = currentPlayer;
}

function checkWinner() {
  let roundWon = false;

  for (let i = 0; i < winConditions.length; i++) {
    const condition = winConditions[i];
    const cellA = options[condition[0]];
    const cellB = options[condition[1]];
    const cellC = options[condition[2]];

    if (cellA === '' || cellB === '' || cellC === '') {
      continue;
    }

    if (cellA === cellB && cellB === cellC) {
      roundWon = true;
      break;
    }
  }

  if (roundWon) {
    statusText.textContent = `${currentPlayer} wins!`;
    running = false;
  } else if (!options.includes('')) {
    statusText.textContent = 'Draw!';
    running = false;
  } else {
    changePlayer();
  }
}

function restartGame() {
  options = ['', '', '', '', '', '', '', '', ''];
  cells.forEach((cell) => (cell.textContent = ''));
  statusText.textContent = 'Waiting for players...';
  running = true;
  socket.emit('restart');
}

let playerTurn = 0;

let players = [
    { name: "PLAYER-1", symbol: "X", nWins: 0 },
    { name: "PLAYER-2", symbol: "O", nWins: 0 }
];

function run(index){
    if (board.update_board(Math.floor(index / 3), index % 3, players[playerTurn].symbol)) {
        console.log(playerTurn)
        playerTurn = (playerTurn === 0) ? 1 : 0;
        console.log(playerTurn)
        if (nPlayers === "1" && playerTurn === 1) {
            let x, y;
            let indexes = computer.wrapper();
            x = indexes[0];
            y = indexes[1];
            console.log(x, y);
            if (board.update_board(x, y, computer.symbol)) {
                playerTurn = 0;
            }
        }
    }
    if (board.is_win()) {
        players[(playerTurn + 1) % 2].nWins++;
    }
}
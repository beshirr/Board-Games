let playerTurn = 0;
let player_1Total = 0;
let player_2Total = 0;

function run(index){
    if (!board.game_is_over()) {
        if (board.update_board(Math.floor(index / 5), index % 5, (playerTurn === 0)? player1.symbol : player2.symbol)) {
            check_seq_win();
            playerTurn = (playerTurn === 0) ? 1 : 0;
            if (nPlayers === "1" && playerTurn === 1) {
                computerTurn();
                check_seq_win();
                playerTurn = 0;
            }
        }
    } else {
        game_status();
    }
}


function check_seq_win() {
    if (board.is_win()) {
        if (playerTurn === 0) {
            board.player1Wins++;

        } else {
            board.player2Wins++;
        }
        console.log("Player-", playerTurn, ": ", (playerTurn === 0) ? board.player1Wins : board.player2Wins);
    }
}


function computerTurn() {
    let x, y;
    let indexes = computer.wrapper();
    x = indexes[0];
    y = indexes[1];
    while (!board.update_board(x, y, computer.symbol)) {
        indexes = computer.wrapper();
        x = indexes[0]; y = indexes[1];
    }
}


function game_status () {
    if (board.is_draw()){
        console.log("TIE");
    } else {
        if (board.gameWinner() === 0) {
            player_1Total++;
            console.log("player1 wins")
        } else {
            console.log("player2 wins")
            player_2Total++;
        }
    }
}

function resetPlayerTurn() {
    playerTurn = 0;
}

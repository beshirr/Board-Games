let playerTurn = 0;


function run(index){
    if (!gameActive) {
        return;
    }
    if (!board.game_is_over()) {
        if (board.update_board(Math.floor(index / 3), index % 3, (playerTurn === 0)? player1.symbol : player2.symbol)) {
            if (game_status()) {
                return;
            }
            playerTurn = (playerTurn === 0) ? 1 : 0;
            if (nPlayers === "1" && playerTurn === 1) {
                computerTurn();
                game_status();
                if (game_status()) {
                    return;
                }
                playerTurn = 0;
            }
        }
    } else {
        game_status();
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


function resetPlayerTurn() {
    playerTurn = 0;
    gameActive = true;
}


function game_status() {
    if (!gameActive) {
        return;
    }
    if (board.is_win()) {
        if (playerTurn === 0) {
            player_2Total++;
        } else {
            player_1Total++;
        }
        game_is_won = true;
        gameActive = false;
        return true;
    } else if (board.is_draw()) {
        game_is_drawn = true;
        game_is_won = false;
        gameActive = false;
    }
}


function playAgain() {
    board.reset_Board();
}

function resetScore() {
    player_1Total = 0;
    player_2Total = 0;
}

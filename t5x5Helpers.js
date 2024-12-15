let playerTurn = 0;

function run(index){
    if (!gameActive) {
        return;
    }

    if (board.game_is_over()) {
        gameEvalutaion();
        return;
    }

    if (board.update_board(Math.floor(index / 5), index % 5, (playerTurn === 0)? player1.symbol : player2.symbol)) {
        game_status()


        playerTurn = (playerTurn === 0) ? 1 : 0;
        if (nPlayers === "1" && playerTurn === 1) {
            computerTurn();
            game_status()
            playerTurn = 0;
        }
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
    if (!gameActive) {
        return;
    }

    if (board.is_win()) {
        if (playerTurn === 0) {
            board.player1Wins++;
            player1_seqScore++;
        } else {
            board.player2Wins++;
            player2_seqScore++;
        }
    }
}

function gameEvalutaion() {
    if (board.is_draw()) {
        game_is_drawn = true;
        game_is_won = false;
        gameActive = false;
        return true;
    }
    else {
        if (playerTurn === 0) {
            player_1Total++;
        } else {
            player_2Total++;
        }
        game_is_won = true;
        gameActive = false;
        game_is_drawn = false;
        return true;
    }
}

function resetPlayerTurn() {
    playerTurn = 0;
    gameActive = true;
    resetScore();
}

function resetScore() {
    player_1Total = 0;
    player_2Total = 0;
    player1_seqScore = 0;
    player2_seqScore = 0;
    board.player1Wins = 0;
    board.player2Wins = 0;
}

function playAgain() {
    player1_seqScore = 0;
    player2_seqScore = 0;
    board.player1Wins = 0;
    board.player2Wins = 0;
    board.reset_Board();
}


class OpenCommand implements Command {
    private BoardScreen boardscreen;

    public OpenCommand(BoardScreen boardScreen) {
        this.boardscreen = boardScreen;
    }

    @Override
    public void excute() {
        boardscreen.open();
    }
}

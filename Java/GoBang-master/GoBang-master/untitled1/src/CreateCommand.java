class CreateCommand implements Command {
    private BoardScreen boardscreen;

    public CreateCommand(BoardScreen boardScreen) {
        this.boardscreen = boardScreen;
    }

    @Override
    public void excute() {
        boardscreen.create();
    }
}

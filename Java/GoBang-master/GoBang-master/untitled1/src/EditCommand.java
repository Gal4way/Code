class EditCommand implements Command {
    private BoardScreen boardscreen;

    public EditCommand(BoardScreen boardScreen) {
        this.boardscreen = boardScreen;
    }

    @Override
    public void excute() {
        boardscreen.edit();
    }
}

class MenuItem {
    private Command command;

    public MenuItem(Command command) {
        this.command = command;
    }

    public void click() {
        this.command.excute();
    }
}

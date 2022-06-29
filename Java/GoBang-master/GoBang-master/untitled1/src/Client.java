import java.util.ArrayList;
public class Client{
    public static void main(String[] args){
        BoardScreen boardScreen = new BoardScreen();
        Menu menu = new Menu();

        MenuItem openItem = new MenuItem(new OpenCommand(boardScreen));
        MenuItem createItem = new MenuItem(new CreateCommand(boardScreen));
        MenuItem editItem = new MenuItem(new EditCommand(boardScreen));

        menu.addMenuItem(openItem);
        menu.addMenuItem(createItem);
        menu.addMenuItem(editItem);

        openItem.click();
        createItem.click();
        editItem.click();
    }
}




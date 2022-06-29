import java.util.ArrayList;

class Menu {
    private ArrayList<MenuItem> MenuItemsList = new ArrayList<MenuItem>();

    public void addMenuItem(MenuItem item) {
        MenuItemsList.add(item);
    }
}

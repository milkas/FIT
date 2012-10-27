package strategy;

/**
 *
 * @author Miroslav Hrstka
 */
public class DFS implements Strategy {
    int[] pole;
    
    public DFS(int[] pole){
        this.pole=pole;
    }

    @Override
    public void vypis(int it) {
        if (it < pole.length) {
            System.out.print(pole[it] + " ");
            vypis(2*it);
            vypis(2*it + 1);
        }
    }
}
//dfsdsfsdfsd
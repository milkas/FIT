package strategy;


/**
 *
 * @author Miroslav Hrstka
 */
public class BFS implements Strategy {
    int[] pole;
    
    public BFS(int[] pole){
        this.pole=pole;
    }
    
    @Override
    public void vypis(int it) {
        if (it<pole.length){
        System.out.print(pole[it] + " ");
        vypis(++it);
        }
    }
}

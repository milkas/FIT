/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package strategy;

/**
 *
 * @author mira
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //binární strom v poli
        int pole[] = {0, 1, 2, 3, 4, 5, 7, 8, 6, 11, 12, 13, 9, 10};


        vypisStrom(pole, args[0]);
    }

    private static void vypisStrom(int[] pole, String strategy) {
        if (strategy.equals("dfs")) {
            Strategy dfs = new DFS(pole);
            System.out.println("výpis stromu DFS:");
            dfs.vypis(1);
            System.out.println("");
        } else if (strategy.equals("bfs")) {
            Strategy bfs = new BFS(pole);
            System.out.println("výpis stromu BFS:");
            bfs.vypis(1);
            System.out.println("");
        } else {
            System.out.println("chybně zvolená strategie");
    }
}
}

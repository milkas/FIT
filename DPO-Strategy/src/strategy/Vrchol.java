/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package strategy;

/**
 *
 * @author mira
 */
 class Vrchol {
	
    int klic;
    String data;
    Vrchol levy;
    Vrchol pravy;

    Vrchol (int klic, String data) {
      this.klic = klic;
      this.data = data;
    }

    void tiskVrcholu() {
      System.out.print(data+" ");
    }
  }

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package strategy;

/**
 *
 * @author mira
 */
  class Strom {
	
    private Vrchol koren;
	
    Strom() {
      koren = null;
    }
    
    public Vrchol getKoren(){
        return koren;
    }
	
    private Vrchol vlozR(Vrchol v, int klic, String data) {
      if (v == null) {
        return new Vrchol(klic,data);
      }
      if (klic < v.klic) {
        v.levy = vlozR(v.levy, klic, data);
      } 
      else {
        v.pravy = vlozR(v.pravy, klic, data);
      }
      return v;
    }

    void vloz(int klic, String data) {
      koren = vlozR(koren, klic, data);
    }
	
    // Preorder
    void preorder(Vrchol v) {
      if (v == null) {
        return;
      } 
      else {    		
        v.tiskVrcholu();
        preorder(v.levy);
        preorder(v.pravy);    
      }
    }
	
    void pruchodPreorder() {
      preorder(koren);
    }
	
    // Inorder
    void inorder(Vrchol v) {
      if (v == null) {
        return;
      } 
      else {    		
        inorder(v.levy);
        v.tiskVrcholu();    		
        inorder(v.pravy);    
      }
    }	
	
    void pruchodInorder() {
      inorder(koren);
    }
	
    //Postorder
    void postorder(Vrchol v) {
      if (v == null) {
        return;
      } 
      else {    		
        postorder(v.levy);
        postorder(v.pravy);    
        v.tiskVrcholu();
      }
    }
	
    void pruchodPostorder() {
      postorder(koren);
    }	

    // Vyhledavani
    private String hledejR(Vrchol v, int klic) {
      if (v == null) {
        return null;
      }
      if (klic == v.klic) {
        return v.data;
      }
      if (klic < v.klic) {
        return hledejR(v.levy, klic);
      }
      else {
        return hledejR(v.pravy, klic);
      }
    }

    String hledej(int klic) {
      return hledejR(koren, klic);
    }
  }

import sun.net.www.content.text.plain;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Descriptografando {
    public static void decode(String plaintext, String keyword) {
        int i = 0;
        int size = plaintext.length();
        int sizekey = keyword.length();
        int cont = 0;
        for (i = 0; i < size; i++) {
            System.out.printf("%c", plaintext.charAt(i) + keyword.charAt(cont) - 'A');
            if (cont == sizekey - 1)
                cont = 0;
            else
                cont++;
        }
    }

    public static void eNcode(String plaintext, String keyword) {
        int i = 0;
        int size = plaintext.length();
        int sizekey = keyword.length();
        int cont = 0;
        for (i = 0; i < size; i++) {
            System.out.printf("%c", plaintext.charAt(i) - keyword.charAt(cont) + 'A');
            if (cont == sizekey - 1)
                cont = 0;
            else
                cont++;
        }
    }

    public static void main(String[] args) {
        String nome = "C:\\Users\\gyova\\Documents\\MEGA\\BTI\\7º PERIODO\\SEGURANÇA\\VigenereCipher\\Cifra_de_Vigenere\\GYOVANNE.txt";
        try {
            FileReader arq = new FileReader(nome);
            BufferedReader lerArq = new BufferedReader(arq);
            String linha = lerArq.readLine();
            decode(linha, "IT");
            arq.close();
        } catch (Exception e) {
            System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
        }
    }
}
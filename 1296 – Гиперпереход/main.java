import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int count = in.nextInt();
        int last_position=0;
        int one_position=0;
        for (int c = 0; c < count; c++) {
            int position = in.nextInt();
            one_position=one_position+position;
            if (one_position>last_position){//сравниваем предыдущую позицию с текущей
                last_position=one_position;
            }
            if (one_position<=0){//если «невыгодно», т.е. меньше 0, присваиваем ноль
                one_position=0;
            }
        }
        System.out.println(last_position);
    }
}





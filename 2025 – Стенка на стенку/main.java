import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int count = in.nextInt();
        int answer[]=new int[count];
        for (int c = 0; c < count; c++) {
            int fighters = in.nextInt();
            int group = in.nextInt();
            int result = 0;
            int t = fighters;
            if (fighters > group) {
                int dividing_groups[] = new int[group];
                int i = 0;
                //filling the array for work with it
                while (t != 0) {
                    if (i == group) {
                        i = 0;
                    }
                    dividing_groups[i]++;
                    i++;
                    t--;
                }
                //getting result
                int s = 0;
                for (i = 0; i < group; i++) {
                    for (s = i + 1; s < group; s++) {
                        result = result + dividing_groups[i] * dividing_groups[s];
                    }
                }
            } else if (fighters == group) {
                while (t != 0) {
                    result = result + (t - 1);
                    t--;
                }
            }
            answer[c]=result;
        }
        for (int d=0; d<count; d++){
            System.out.println(answer[d]);
        }
        in.close();
    }
}









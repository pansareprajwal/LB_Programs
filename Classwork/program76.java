import java.io.*;

class program76
{
    public static void main(String A[]) throws IOException
    {
        int iNo = 0;
        int i = 0;

        BufferReader bobj = new BufferReader(new InputStreamReader(System.in));

        System.out.println(x: "Enter number : ");
        
        iNo = Integer.parseInt(bobj.readline());

        for(i=1; i <= (iNo/2); i++)
        {
            if((iNo % i) == 0)
            {
                System.out.println(i);
            }
        }
    }
}
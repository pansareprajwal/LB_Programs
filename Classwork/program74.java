// checked exception

import java.io.*;

class program74
{
    public static void main(String A[])
    {
        int iNo = 0;
        int i = 0;

        BufferReader bobj = new BufferReader(new InputStreamReader(System.in));

        System.out.println("Enter number : ");
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
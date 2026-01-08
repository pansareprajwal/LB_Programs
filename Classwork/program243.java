// input : hello
// output : h   e   l   l   o

import java.util.*;

class program243
{
    public static void main(String A[])
    {      
        int iCnt = 0;
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        System.out.println("Input is : "+str);
        System.out.println("Length of string is : "+str.length());

        for(iCnt = 0; iCnt < str.length(); iCnt++)
        {
            System.out.println(str.charAt(iCnt));
        }
    }
}
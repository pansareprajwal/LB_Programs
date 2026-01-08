//  Summation of all elements of array

import java.util.*;

class ArrayX
{
    public void Display(int Brr[])
    {
        int i = 0;

        System.out.println("Elments of the array are :");
        for(i = 0; i < Brr.length; i++)
        {
            System.out.println(Brr[i]);
        }
    }

    public int Summation(int Brr[])
    {
        int i = 0;
        int iSum = 0;

        for(i = 0; i < Brr.length; i++)
        {
            iSum = iSum + Brr[i];
        }

        return iSum;
    }
}

class program102
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        int iSize = 0, i = 0, iRet = 0;

        System.out.println("Enter the size of an elements : ");
        iSize = sobj.nextInt();
        
        int Arr[] = new int[iSize];

        System.out.println("Enter the elements : ");

        for(i = 0; i < Arr.length; i++)
        {
            Arr[i] = sobj.nextInt();
        } 

        ArrayX aobj = new ArrayX();
        aobj.Display(Arr);

        iRet = aobj.Summation(Arr);
        System.out.println("Summation of the elements are : "+iRet);

        aobj = null;
        Arr = null;
        sobj = null;

        System.gc();
    }
}
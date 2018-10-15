package files;

import java.io.*;

public class File1 {
	static Print p =new Print();
	static void copy(File f1,File f2) 
	{
		 
		
		try {
			FileReader fin=new FileReader(f1);
			FileWriter fout=new FileWriter(f2);
			BufferedReader br=new BufferedReader(new FileReader(f1));
			PrintWriter pw=new PrintWriter(fout,true);
			String str[]=new String[100];
			p.print("file 2 exists: "+f2.exists());
			p.print("file 2 writable: "+f2.canWrite());
			for(int i=0;(str[i]=br.readLine())!=null;i++)
			{			
				p.print(""+str[i]);
				pw.println("Line "+(i+1)+"  :"+str[i]);
				
				
			}
			
			fin.close();
			fout.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
			
		
		
	}
	
	static void words(File f1)
	{
		try {			
			BufferedReader br=new BufferedReader(new FileReader(f1));
			int c;
			int lines=1,words=0,chars=0,nums=0;
			boolean prevSpace=false;
			while((c=br.read())!=-1)
			{				
				c=(char)c;
				if(c=='\n')
				{	lines++;
					words++;
				}
				
				
				if(c==' ')
				{
					
					if(prevSpace==true)
					{
						//do nothing
					}
					else
					{
						prevSpace=true;
						words++;
					}
				}
				
				if((c>='a' && c<='z')|| (c>='A' && c<='Z'))
				{
					chars++;
					prevSpace=false;
				}
				if((int)c>=0)
				{
					nums++;
				}
				
			}
			p.print("\nLines = "+lines+" Words = "+words+" characters = "+chars);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			File fin=new File("D:\\Education\\Cse");
			File f1 =new File("D:\\Education\\Cse\\FileTest1.txt");
			File f2 =new File("D:\\Education\\Cse\\File2.txt");
			p.print(""+f1.exists());
			p.print("Is readable: "+f1.canRead());
			p.print("Size: "+f1.length());
			p.print("Is a directory: "+f1.isDirectory());
			File list[]=fin.listFiles();
			for(File x: list)
			{				
				if(x.isDirectory())
					p.print("Directory: "+x.getName());
				else
					p.print("File: "+x.getName());
			}
			
			copy(f1,f2);
			words(f1);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}

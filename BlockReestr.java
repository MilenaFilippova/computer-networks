//Программа должна считывать реестр из файла (прилагается к заданию в виде архива).
//Пользователь вводит URL сайта, который нужно проверить на предмет блокировки.
import java.util.Scanner;
import java.io.FileReader;
import java.net.InetAddress;


public class Main
{

    public static void main(String[] args) throws Exception
    {
        //с помощью FileReader - считываем файл
        FileReader file = new FileReader("register.txt");
        Scanner file_in = new Scanner(file);
        Scanner sc = new Scanner(System.in);
        boolean result_URL = false, result_DOMAIN = false, result_IP = false;
        String url = sc.nextLine();
        String[] str = url.split("/");  // split() — в Java разделяет данную строку вокруг данного регулярного выражения
        String dom = str[2];//берем необходимый фрагмент сроки
        String[] ip = InetAddress.getByName(dom).toString().split("/");  //InetAddress определит IP адрес введенного домена
        String[] temp;



        //для каждой строки,пока не конец файла
        while (file_in.hasNextLine())
        {

            temp = file_in.nextLine().split(";");
            str = temp[1].split(",");
            for (int j = 0; j < str.length;j++)
            {
                //compareTo в Java сравнивает вызывающий объект с объектом-параметрм
                //ищем совпадения искомого url в списке запрещенных
                if (url.compareTo(str[j]) == 0)
                    result_URL = true;
            }


            str = temp[2].split(",");
            for (int n = 0; n < str.length;n++)
            {
                if (dom.compareTo(str[n]) == 0)
                    result_DOMAIN = true;
            }


            str = temp[3].split(",");
            for (int m = 0;m < str.length;m++)
            {
                if (ip[1].compareTo(str[m]) == 0)
                    result_IP = true;
            }

        }

        //если хоть одна проверка не пройдена, говорим,что блокирован
        if (result_URL == true || result_DOMAIN == true || result_IP == true)
        {
            if (result_URL)
                System.out.println("This URL is blocked");
            if (result_DOMAIN)
                System.out.println("This domain is blocked");
            if (result_IP)
                System.out.println("This IP is blocked");
        }
        else
        {
            System.out.println("Nothing is blocked");
        }

        //закрываем поток для чтения файла
        file.close();
    }

}

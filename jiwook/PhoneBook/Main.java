package study;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        PhoneBook phoneBook = new PhoneBook(); // 빈 전화번호부 객체 생성
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.print("명령어(ADD, SEARCH, EXIT): ");
            String command = scanner.nextLine().toUpperCase();

            switch (command) {
                case "ADD":
                    phoneBook.addContact();
                    break;
                case "SEARCH":
                    phoneBook.searchContact();
                    break;
                case "EXIT":
                    System.out.println("프로그램을 종료합니다.");
                    return;
                default:
                    System.out.println("ADD,SEARCH,EXIT 중에 입력부탁드려요");
            }
        }
    }
}
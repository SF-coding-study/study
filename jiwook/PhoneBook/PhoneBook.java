package study;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PhoneBook {
    private List<Contact> contacts; // ArrayList를 사용하여 연락처를 관리 동적 배열
    private static final int MAX_CONTACTS = 8; // 최대 연락처 수 final로 상수지정

    public PhoneBook() {
        this.contacts = new ArrayList<>(); // ArrayList로 초기화
    }

    public void addContact() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("이름: ");
        String firstName = scanner.nextLine().trim();
        if (firstName.isEmpty()) {
            System.out.println("입력을 안 하셔서 메뉴로 돌아갑니다.");
            return;
        }

        System.out.print("성: ");
        String lastName = scanner.nextLine().trim();
        if (lastName.isEmpty()) {
            System.out.println("입력을 안 하셔서 메뉴로 돌아갑니다.");
            return;
        }

        System.out.print("닉네임: ");
        String nickname = scanner.nextLine().trim();
        if (nickname.isEmpty()) {
            System.out.println("입력을 안 하셔서 메뉴로 돌아갑니다.");
            return;
        }

        System.out.print("전화번호: ");
        String phoneNumber = scanner.nextLine().trim();
        if (phoneNumber.isEmpty()) {
            System.out.println("입력을 안 하셔서 메뉴로 돌아갑니다.");
            return;
        }

        System.out.print("비밀: ");
        String secret = scanner.nextLine().trim();
        if (secret.isEmpty()) {
            System.out.println("입력을 안 하셔서 메뉴로 돌아갑니다.");
            return;
        }

        Contact contact = new Contact(firstName, lastName, nickname, phoneNumber, secret);
        if (contacts.size() < MAX_CONTACTS) {
            contacts.add(contact); // 리스트에 연락처 추가
        } else {
            contacts.remove(0); // 가장 오래된 연락처 제거
            contacts.add(contact); // 새로운 연락처 추가
        }
        System.out.println("연락처가 저장되었습니다.");
    }

    public void searchContact() {
        if (contacts.isEmpty()) {
            System.out.println("저장된 연락처가 없습니다.");
            return;
        }

        System.out.printf("|%10s|%10s|%10s|%10s|\n", "위치", "이름", "성", "별명");
        for (int i = 0; i < contacts.size(); i++) {
            Contact c = contacts.get(i);
            System.out.printf("|%10d|%10s|%10s|%10s|\n",
                    i,
                    cut(c.getFirstName()),
                    cut(c.getLastName()),
                    cut(c.getNickname()));
        }

        Scanner scanner = new Scanner(System.in);
        System.out.print("조회할 연락처의 인덱스를 입력하세요: ");
        String input = scanner.nextLine();
        try {
            int index = Integer.parseInt(input);
            Contact c = getContact(index);
            if (c != null) {
                System.out.println("이름: " + c.getFirstName());
                System.out.println("성: " + c.getLastName());
                System.out.println("닉네임: " + c.getNickname());
                System.out.println("전화번호: " + c.getPhoneNumber());
                System.out.println("비밀: " + c.getSecret());
            } else {
                System.out.println("유효하지 않은 인덱스입니다.");
            }
        } catch (NumberFormatException e) {
            System.out.println("숫자를 입력해야 합니다.");
        }
    }

    private Contact getContact(int index) {
        if (index >= 0 && index < contacts.size()) {
            return contacts.get(index);
        }
        return null;
    }

    private String cut(String str) {
        if (str.length() > 10) {
            return str.substring(0, 9) + ".";
        }
        return String.format("%10s", str);
    }
}
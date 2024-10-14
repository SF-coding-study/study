package study;


public class Contact {
    private String firstName;
    private String lastName;
    private String nickname;
    private String phoneNumber;
    private String secret;

    // 생성자
    public Contact(String firstName, String lastName, String nickname, String phoneNumber, String darkestSecret) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.nickname = nickname;
        this.phoneNumber = phoneNumber;
        this.secret = darkestSecret;
    }

    // 각 필드의 getter 메서드
    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getNickname() {
        return nickname;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public String getSecret() {
        return secret;
    }
}

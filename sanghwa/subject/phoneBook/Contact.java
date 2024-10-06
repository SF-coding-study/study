package study.sanghwa.subject.phoneBook;

public record Contact(
	String firstName,
	String lastName,
	String nickname,
	String phoneNumber,
	String darkestSecret
) {
	public static Contact of(String[] values) {
		if (!validate(values)) {
			throw new IllegalArgumentException();
		}
		return new Contact(
			values[0],
			values[1],
			values[2],
			values[3],
			values[4]
		);
	}

	private static boolean validate(String[] values) {
		boolean allValuesValid = true;
		for (String value : values) {
			if (value.isEmpty()) {
				allValuesValid = false;
				break;
			}
		}
		return allValuesValid;
	}

	@Override
	public String toString() {
		return "firstName : " + firstName + "\n"
			+ "lastName : " + lastName + "\n"
			+ "nickname : " + nickname + "\n"
			+ "phoneNumber : " + phoneNumber + "\n"
			+ "darkestSecret : " + darkestSecret + "\n";
	}
}

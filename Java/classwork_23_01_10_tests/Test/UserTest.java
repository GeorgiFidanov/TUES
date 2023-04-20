import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import static org.junit.jupiter.api.Assertions.*;

class UserTest {
    @Test
    @DisplayName("Test making users")
    void createUserTest() throws InvalidValue {
        User us1 = new User(21, "Steven");
        Assertions.assertEquals("Steven", us1.getUsername());
        Assertions.assertEquals(21, us1.getAge());

        User us2 = new User(23, "Pesho");
        Assertions.assertEquals("Pesho", us2.getUsername());
        Assertions.assertEquals(23, us2.getAge());
    }

    @ParameterizedTest(name = "With age: {0}")
    @ValueSource(ints = {-4, -10, -100, 0})
    @DisplayName("Test invalid ages")
    void invalidAgeTest(int age) throws InvalidValue {
        assertThrows(InvalidValue.class, () -> new User(age, "NonExistent"));
    }



    @Nested
    class BasicFileTests {
        private final User thanos = new User(1000, "Thanos");

        BasicFileTests() throws InvalidValue {
        }

        @Test
        void addFileTest() throws InvalidValue, TooManyFiles  {

            File<String> stringFile = new File<>("file1.txt", 4);
            stringFile.addContent("*SNAP*");
            thanos.addFile(stringFile);

            Assertions.assertEquals(1, thanos.getFiles().size());

            File<Integer> numberFile = new File<>("file2.txt", 12);
            numberFile.addContent(100);
            thanos.addFile(numberFile);

            Assertions.assertEquals(2, thanos.getFiles().size());

        }

        @Test
        void testDuplicates() throws InvalidValue, TooManyFiles {
            File<String> stringFile = new File<>("file1.txt", 4);
            stringFile.addContent("*SNAP*");
            thanos.addFile(stringFile);

            File<String> fileCheck = new File<>("file1.txt", 100);
            Assertions.assertTrue(thanos.hasFile(fileCheck));
        }
    }

    @Test
    @DisplayName("Test files limit")
    void maxFilesTest() throws InvalidValue, TooManyFiles {
        User us1 = new User(21, "Steven");
        us1.addFile(new File<String>("name1.txt", 4));
        us1.addFile(new File<String>("name2.txt", 45));
        us1.addFile(new File<String>("name3.txt", 46));

        Assertions.assertThrows(TooManyFiles.class, () ->
                us1.addFile(new File<String>("name4.txt", 47))
        );

    }

}
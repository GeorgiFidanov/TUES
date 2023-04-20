import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.ValueSource;

import java.text.Format;

import static org.junit.jupiter.api.Assertions.*;

class FileTest {
    @Test
    @DisplayName("Test files creation")
    void testBasicCreation() {
        Assertions.assertDoesNotThrow(() -> new File<Character>("file1.txt", 4));
        Assertions.assertDoesNotThrow(() -> new File<String>("file5.txt", 12));
    }

    @ParameterizedTest
    @ValueSource(strings = {"BIGFILE", "MASSIVE", "COOL123", "file", "EpIc1.Txt"})
    void testLowercaseNames(String name) throws InvalidValue {
        File<String> fl = new File<>(name, 10);
        Assertions.assertEquals(name.toLowerCase(), fl.getName());
    }

    @ParameterizedTest
    @ValueSource(ints = {-10, -1000})
    @DisplayName("Test creating files with invalid sizes")
    void invalidSize(int size) throws InvalidValue {
        assertThrows(InvalidValue.class, () -> new File<Boolean>("bool.txt", size));
    }

    @Test
    @DisplayName("Test files content")
    void readContentTest() throws InvalidValue {
        File<String> fl1 = new File<>("file5.txt", 12);
        fl1.addContent("Epic content!");

        Assertions.assertEquals("Epic content!", fl1.getContent());

        File<Integer> fl2 = new File<>("number.txt", 200);
        fl2.addContent(41);

        Assertions.assertEquals(41, fl2.getContent());
    }

    @Test
    @DisplayName("Test file content with custom object")
    void customObjectsContentTest() throws InvalidValue {
        File<File<Integer>> folder = new File<>("folder", 1000);
        File<Integer> innerFile = new File<>("random.txt", 10);
        innerFile.addContent(100);
        folder.addContent(innerFile);

        File<Integer> innerFileCopy = new File<>("random.txt", 10);
        innerFileCopy.addContent(100);

        Assertions.assertEquals(100, folder.getContent().getContent());
        Assertions.assertEquals(innerFileCopy, folder.getContent());
    }




}
package dxc.add.exception;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.HttpServerErrorException;
import dxc.add.model.ErrorDTO;

import java.util.ArrayList;
import java.util.List;

@ControllerAdvice
public class GlobalExceptionHandler extends RuntimeException {

    @ExceptionHandler(ApiException.class)
    public ResponseEntity<Object> handleApiException(ApiException exception) {
        return ResponseEntity.status(exception.getHttpStatus()).body(new ErrorDTO().error(exception.getMessage()));
    }

    @ExceptionHandler({Exception.class})
    public ResponseEntity<Object> handleAllException(Exception exception) {
        return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body(exception.getMessage());
    }

    @ExceptionHandler({HttpClientErrorException.class, HttpServerErrorException.class})
    public ResponseEntity<Object> handleHttpClientServerErrorException(HttpClientErrorException exception) {
        return ResponseEntity.status(exception.getStatusCode()).build();
    }

    @ResponseStatus(HttpStatus.BAD_REQUEST)
    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<Object> handleValidationExceptions(MethodArgumentNotValidException exception) {
        List<ErrorDTO> errors = new ArrayList<>();

        exception.getBindingResult().getFieldErrors()
                .forEach(e -> errors.add(new ErrorDTO().error(e.getField() + " " + e.getDefaultMessage())));

        return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(errors);
    }

}

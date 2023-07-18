import { Component, Input, Output, EventEmitter } from '@angular/core';

export type CheckboxData = {
  id: string,
  value: boolean,
  name: string
}[];

export type CheckboxReturnValue = {
  id: string,
  value: boolean,
  name: string
}

@Component({
  selector: 'app-checkbox',
  templateUrl: './checkbox.component.html',
  styleUrls: ['./checkbox.component.css']
})
export class CheckboxComponent {
  @Input() listOfAnswers: CheckboxData = [];
  @Input() question = '';
  @Output() returnCheckboxValue: EventEmitter<CheckboxReturnValue> = new EventEmitter<CheckboxReturnValue>();

  onCheckboxChange(checkboxReturnValue: CheckboxReturnValue): void {
    checkboxReturnValue.value = !checkboxReturnValue.value;
    this.returnCheckboxValue.emit(checkboxReturnValue);
  }
}

import { Component, EventEmitter, Input, Output  } from '@angular/core';

export type RadioButtonsData = {
  id: string,
  name: string
}[]

export type ReturnRadioButtonsValue = {
  id: string,
  name: string
}
@Component({
  selector: 'app-radio-buttons',
  templateUrl: './radio-buttons.component.html',
  styleUrls: ['./radio-buttons.component.css']
})
export class RadioButtonsComponent {
  @Input() question = '';
  @Input() radioButtonsData: RadioButtonsData = [];
  @Output() returnRadioButtonsValue: EventEmitter<ReturnRadioButtonsValue> = new EventEmitter<ReturnRadioButtonsValue>();

  checkedId = '';

  isChecked(id: string) {
    return this.checkedId === id;
  }

  onRadioButtonChange(id: string) {
    this.checkedId = id;
    const checkedButton = this.radioButtonsData.find(x => x.id === id);
    this.returnRadioButtonsValue.emit(checkedButton);
  }
}

import { Component, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-dropdown',
  templateUrl: './dropdown.component.html',
  styleUrls: ['./dropdown.component.css']
})
export class DropdownComponent {
  @Input() question = '';
  @Input() listOfAnswers: string[] = [];
  @Output() returnDropdownValue: EventEmitter<string> = new EventEmitter<string>();

  selectedValue = '';

  onDropdownChange(event: Event): void {
    const selected = event.target as HTMLOptionElement;
    this.selectedValue = selected.value;
    this.returnDropdownValue.emit(this.selectedValue);
  }

}

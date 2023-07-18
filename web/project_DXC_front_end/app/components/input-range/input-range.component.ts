import { Component, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-input-range',
  templateUrl: './input-range.component.html',
  styleUrls: ['./input-range.component.css']
})
export class InputRangeComponent {
  @Input() question = '';
  @Input() value = '';
  @Output() returnInputRangeValue: EventEmitter<string> = new EventEmitter<string>();

  onInputRangeChange(event: Event) {
    const inputRange = event.target as HTMLInputElement;
    this.returnInputRangeValue.emit(inputRange.value);
  }
}
